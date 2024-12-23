#include "Post.hpp"
#include <iostream>

Post::Post() : id(0), parentId(0), quotedContent("") {}

Post::Post(int id, const std::string& content, const std::string& author, int parentId, const std::string& quotedContent)
    : id(id), content(content), author(author), parentId(parentId), quotedContent(quotedContent) {}

std::string Post::getContent() const {
    return content;
}

std::string Post::getAuthor() const {
    return author;
}

std::string Post::getQuotedContent() const {
    return quotedContent;
}

bool Post::addReply(const Post& reply) {
    if (reply.id == this->id) {
        return false; // A post cannot reply to itself
    }
    replies.push_back(reply);
    return true;
}

int Post::getParentId() const {
    return parentId;
}

int Post::getId() const {
    return id;
}

void Post::display(std::ostream& out, int depth) const {
    for (int i = 0; i < depth; i++) out << "  "; // Indentation
    out << "Post ID: " << id << " | Author: " << author << "\n";

    if (!quotedContent.empty()) {
        for (int i = 0; i < depth; i++) out << "  "; // Indentation
        out << "Quoted: " << quotedContent << "\n";
    }

    for (int i = 0; i < depth; i++) out << "  "; // Indentation
    out << "Content: " << content << "\n";

    for (const auto& reply : replies) {
        reply.display(out, depth + 1);
    }
    out << "\n";
}

std::ostream& operator<<(std::ostream& out, const Post& post) {
    post.display(out);
    return out;
}

std::istream& operator>>(std::istream& in, Post& post) {
    std::cout << "Enter post content: ";
    std::getline(in, post.content);
    std::cout << "Enter post author: ";
    std::getline(in, post.author);
    return in;
}
